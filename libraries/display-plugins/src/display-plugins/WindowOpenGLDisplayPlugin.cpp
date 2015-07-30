//
//  Created by Bradley Austin Davis on 2015/05/29
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#include "WindowOpenGLDisplayPlugin.h"

#include <QGLWidget>
#include <QOpenGLContext>

#include "plugins/PluginContainer.h"

WindowOpenGLDisplayPlugin::WindowOpenGLDisplayPlugin() {
}

glm::uvec2 WindowOpenGLDisplayPlugin::getRecommendedRenderSize() const {
    uvec2 result;
    if (_window) {
        result = toGlm(_window->geometry().size() * _window->devicePixelRatio());
    }
    return result;
}

glm::uvec2 WindowOpenGLDisplayPlugin::getRecommendedUiSize() const {
    uvec2 result;
    if (_window) {
        result = toGlm(_window->geometry().size());
    }
    return result;
}

bool WindowOpenGLDisplayPlugin::hasFocus() const {
    return _window ? _window->hasFocus() : false;
}

void WindowOpenGLDisplayPlugin::activate(PluginContainer * container) {
    OpenGLDisplayPlugin::activate(container);
    _window = container->getPrimarySurface();
    _window->makeCurrent();
    customizeContext(container);
    _window->doneCurrent();
}

void WindowOpenGLDisplayPlugin::deactivate(PluginContainer* container) {
    OpenGLDisplayPlugin::deactivate(container);
    _window = nullptr;
}

void WindowOpenGLDisplayPlugin::makeCurrent() {
    _window->makeCurrent();
}

void WindowOpenGLDisplayPlugin::doneCurrent() {
    _window->doneCurrent();
}

void WindowOpenGLDisplayPlugin::swapBuffers() {
    _window->swapBuffers();
}
//
//void WindowOpenGLDisplayPlugin::installEventFilter(QObject* filter) {
//    _window->installEventFilter(filter);
//}
//
//void WindowOpenGLDisplayPlugin::removeEventFilter(QObject* filter) {
//    _window->removeEventFilter(filter);
//}
//
//QWindow* WindowOpenGLDisplayPlugin::getWindow() const {
//    return _window;
//}