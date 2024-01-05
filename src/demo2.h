#ifndef _DEMO2_H
#define _DEMO2_H

/* Stdio Include */
#include <iostream>

/* Imgui Include */
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// #define GUI_STYLE_LIGHT
// #define GUI_STYLE_DARK
#define GUI_STYLE_CLASSIC

GLFWwindow * window;    // GLFW Opaque window object.

bool demo_window2 = false;

#endif