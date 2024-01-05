#include "demo2.h"

int main (void)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::perror("Initialize GLFW Error!");
        return 1;
    }

    // Create GLFW Window
    window = glfwCreateWindow(854, 480, "Imgui XO Demo Program", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::perror("Create GLFW Window Error!");
        return 1;
    }
    glfwMakeContextCurrent(window); // Makes the context of the specified window current for the calling thread. 

    // Initialize Imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext(); 
    ImGuiIO & io = ImGui::GetIO(); (void)io;
#ifdef  GUI_STYLE_LIGHT
    ImGui::StyleColorsLight();      // Set Style To Light
#elif   defined(GUI_STYLE_DARK)
    ImGui::StyleColorsDark();       // Set Style To Dark
#elif   defined(GUI_STYLE_CLASSIC)
    ImGui::StyleColorsClassic();    // Set Style To Classic
#endif
    io.Fonts->AddFontFromFileTTF("/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf", 20.0f);
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130"); // small case!!!

    // Main Loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Demo Window 1, Set Maximize And Full Screen
        // Disable Window Decoration (Title) & Collapse Button
        ImGui::SetNextWindowPos(ImGui::GetMainViewport()->Pos);
        ImGui::SetNextWindowSize(ImGui::GetMainViewport()->Size);
        if (ImGui::Begin("Demo Window 1", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration))
        {
            ImGui::Text("This is Simple Application\nYou Can Click Select Box To Open Another Window...");
            if (ImGui::Button("Open!!"))
                demo_window2 = true;
        }
        ImGui::End();    

        // Demo Window 2, Click Window 1 Button To Open
        if (demo_window2)
        {
            if (ImGui::Begin("Demo Window 2"))
            {
                ImGui::Text("This is Another Window In Simple Application...");
                if (ImGui::Button("Closed"))
                    demo_window2 = false;
            }
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.00f, 0.00f, 0.00f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Clean Up
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}