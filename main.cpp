#include <SDL.h>
#include <glad/glad.h>
#include <iostream>

int gScreenWidth = 640;
int gScreenHeight = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;
bool gQuit = false;

void GetOpenGLInfo() {
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

}


void InitializeProgram() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize VIDEO subsystem: %s", SDL_GetError());
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gGraphicsApplicationWindow = SDL_CreateWindow("SDL2 OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL);
    if (gGraphicsApplicationWindow == nullptr) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);
    if (gOpenGLContext == nullptr) {
        SDL_Log("Unable to create OpenGL context: %s", SDL_GetError());
        exit(1);
    }

    // Inicializar Glad
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize Glad" << std::endl;
        exit(1);
    }

    GetOpenGLInfo();

}

void Input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gQuit = true;
        }
    }
}

void PreDraw() {

}

void Draw() {
    // Draw something here
}

void MainLoop() {

    SDL_Event event;
    while (!gQuit) {
        Input();
        PreDraw();
        Draw();
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }
}

void CleanUp() {

    SDL_DestroyWindow(gGraphicsApplicationWindow);
    SDL_GL_DeleteContext(gOpenGLContext);

    SDL_Quit();

}


int main(int argc, char* argv[]) {
    InitializeProgram();
    MainLoop();
    CleanUp();
    return 0;
}