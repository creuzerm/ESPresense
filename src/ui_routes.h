/*
 * Web UI Routes
 *
 * Compressed Size Summary:
 * ui_app_immutable_assets_css: 24,888 bytes
 * ui_html: 4,332 bytes
 * ui_app_immutable_entry_js: 63,473 bytes
 * ui_app_immutable_nodes_js: 590 bytes
 * ui_svg: 456 bytes
 * Total: 93,739 bytes
 */

#pragma once

#include <ESPAsyncWebServer.h>
#include "ui_app_immutable_assets_css.h"
#include "ui_html.h"
#include "ui_app_immutable_entry_js.h"
#include "ui_app_immutable_nodes_js.h"
#include "ui_svg.h"

inline void setupRoutes(AsyncWebServer* server) {
    server->on("/app/immutable/assets/internal.B1a9unIV.css", HTTP_GET, serveAppImmutableAssetsInternalB1a9unIvCss);
    server->on("/app/immutable/assets/start.B1a9unIV.css", HTTP_GET, serveAppImmutableAssetsStartB1a9unIvCss);
    server->on("/app/immutable/entry/app.OSCHLIBq.js", HTTP_GET, serveAppImmutableEntryAppOschliBqJs);
    server->on("/app/immutable/entry/start.Buy4t0EV.js", HTTP_GET, serveAppImmutableEntryStartBuy4t0EvJs);
    server->on("/app/immutable/nodes/0.D_qGyeWs.js", HTTP_GET, serveAppImmutableNodes_0DQGyeWsJs);
    server->on("/app/immutable/nodes/1.DVdtkK18.js", HTTP_GET, serveAppImmutableNodes_1DVdtkK18Js);
    server->on("/app/immutable/nodes/2.DMBQs1Kb.js", HTTP_GET, serveAppImmutableNodes_2DmbQs1KbJs);
    server->on("/app/immutable/nodes/3.BLhBO-sl.js", HTTP_GET, serveAppImmutableNodes_3BLhBoSlJs);
    server->on("/app/immutable/nodes/4.jxNTa_Bk.js", HTTP_GET, serveAppImmutableNodes_4JxNTaBkJs);
    server->on("/app/immutable/nodes/5.DiucVLSS.js", HTTP_GET, serveAppImmutableNodes_5DiucVlssJs);
    server->on("/app/immutable/nodes/6.CegLa3XK.js", HTTP_GET, serveAppImmutableNodes_6CegLa3XkJs);
    server->on("/app/immutable/nodes/7.BPi-lQbw.js", HTTP_GET, serveAppImmutableNodes_7BPiLQbwJs);
    server->on("/favicon.svg", HTTP_GET, serveFaviconSvg);
    // HTML routes
    server->on("/devices", HTTP_GET, serveDevicesHtml);
    server->on("/devices.html", HTTP_GET, serveDevicesHtml);
    server->on("/fingerprints", HTTP_GET, serveFingerprintsHtml);
    server->on("/fingerprints.html", HTTP_GET, serveFingerprintsHtml);
    server->on("/hardware", HTTP_GET, serveHardwareHtml);
    server->on("/hardware.html", HTTP_GET, serveHardwareHtml);
    server->on("/", HTTP_GET, serveIndexHtml);
    server->on("/network", HTTP_GET, serveNetworkHtml);
    server->on("/network.html", HTTP_GET, serveNetworkHtml);
    server->on("/settings", HTTP_GET, serveSettingsHtml);
    server->on("/settings.html", HTTP_GET, serveSettingsHtml);
}
