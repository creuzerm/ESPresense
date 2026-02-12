/*
 * Web UI Routes
 *
 * Compressed Size Summary:
 * ui_app_immutable_assets_css: 24,888 bytes
 * ui_html: 4,326 bytes
 * ui_app_immutable_entry_js: 63,470 bytes
 * ui_app_immutable_nodes_js: 590 bytes
 * ui_svg: 456 bytes
 * Total: 93,730 bytes
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
    server->on("/app/immutable/entry/app.DJkYgpuF.js", HTTP_GET, serveAppImmutableEntryAppDJkYgpuFJs);
    server->on("/app/immutable/entry/start._sT3opGu.js", HTTP_GET, serveAppImmutableEntryStartST3opGuJs);
    server->on("/app/immutable/nodes/0.BVyK4f5F.js", HTTP_GET, serveAppImmutableNodes_0BVyK4f5FJs);
    server->on("/app/immutable/nodes/1.62uRSoY9.js", HTTP_GET, serveAppImmutableNodes_1_62uRSoY9Js);
    server->on("/app/immutable/nodes/2.BbhG5Y6V.js", HTTP_GET, serveAppImmutableNodes_2BbhG5Y6VJs);
    server->on("/app/immutable/nodes/3.BPd72MMG.js", HTTP_GET, serveAppImmutableNodes_3BPd72MmgJs);
    server->on("/app/immutable/nodes/4.BYF_uJQm.js", HTTP_GET, serveAppImmutableNodes_4ByfUJQmJs);
    server->on("/app/immutable/nodes/5.Dgsua-RG.js", HTTP_GET, serveAppImmutableNodes_5DgsuaRgJs);
    server->on("/app/immutable/nodes/6.ByyFVsL0.js", HTTP_GET, serveAppImmutableNodes_6ByyFVsL0Js);
    server->on("/app/immutable/nodes/7.BtcKVkXL.js", HTTP_GET, serveAppImmutableNodes_7BtcKVkXlJs);
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
