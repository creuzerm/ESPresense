from playwright.sync_api import Page, expect, sync_playwright

def test_mesh_fix_checkbox(page: Page):
    page.on("console", lambda msg: print(f"Console: {msg.text}"))
    page.on("pageerror", lambda msg: print(f"PageError: {msg}"))

    # Mock the /wifi/main endpoint
    def handle_wifi_main(route):
        print("Handling /wifi/main")
        route.fulfill(
            status=200,
            content_type="application/json",
            body="""{
            "values": {
                "room": "test-room",
                "wifi_timeout": 60,
                "portal_timeout": 300,
                "wifi-ssid": "test-ssid",
                "wifi-password": "test-password",
                "persistent_wifi": false,
                "eth": "0",
                "mqtt_host": "mqtt.local",
                "mqtt_port": 1883,
                "mqtt_user": "",
                "mqtt_pass": "",
                "discovery": true,
                "discovery_prefix": "homeassistant",
                "pub_tele": true,
                "pub_rooms_dep": false,
                "pub_devices": true,
                "auto_update": true,
                "prerelease": false,
                "arduino_ota": true,
                "update": ""
            },
            "defaults": {
                "room": "espresense",
                "wifi-ssid": "",
                "wifi-password": "",
                "persistent_wifi": false,
                "wifi_timeout": 60,
                "portal_timeout": 300,
                "eth": "0",
                "mqtt_host": "",
                "mqtt_port": 1883,
                "discovery": true,
                "discovery_prefix": "homeassistant",
                "pub_tele": true,
                "pub_rooms_dep": false,
                "pub_devices": true,
                "auto_update": true,
                "prerelease": false,
                "arduino_ota": true
            }
        }"""
        )

    page.route("**/wifi/main", handle_wifi_main)

    # Also need to mock /wifi/scan as it is called on mount
    page.route("/wifi/scan", lambda route: route.fulfill(
        status=200,
        content_type="application/json",
        body='{"networks": {"test-ssid": -50}}'
    ))

    # Mock other requests that might happen
    page.route("/json", lambda route: route.fulfill(status=200, body='{"room": "test-room"}'))
    page.route("/json/configs", lambda route: route.fulfill(status=200, body='{"room": "test-room", "configs": []}'))
    page.route("/json/devices?showAll", lambda route: route.fulfill(status=200, body='{"room": "test-room", "devices": []}'))

    # Navigate to the network page
    page.goto("http://localhost:3000/network")

    # Wait for the form to load (it depends on mainSettings)
    # The form has class "space-y-6"
    expect(page.locator("form")).to_be_visible()

    print("Form found")

    # Verify the checkbox exists
    checkbox = page.locator("#persistent-wifi")
    expect(checkbox).to_be_visible()

    # Verify the label text
    label = page.locator("label[for='persistent-wifi']")
    expect(label).to_contain_text("Disable WiFi Persistence (for Better Mesh Router Support)")

    # Verify the description text
    description = page.locator("label[for='persistent-wifi'] + p")
    expect(description).to_contain_text("Forces a full network scan on every reboot")

    # Take a screenshot
    print("Taking screenshot")
    page.screenshot(path="/home/jules/verification/verification.png")
    print("Screenshot taken")

if __name__ == "__main__":
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True)
        page = browser.new_page()
        try:
            test_mesh_fix_checkbox(page)
        finally:
            browser.close()
