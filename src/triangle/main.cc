#include "main.ih"

int main(void)
try
{
    /* Initialize the library */
    if (!glfwInit())
        throw std::runtime_error{ "Failed to initialize GLFW" };

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error{ "Failed to create window" };
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize glew
    GLenum err = glewInit();
    if (err != GLEW_OK)
        throw std::runtime_error{ reinterpret_cast<char const *>
                                                (glewGetErrorString(err)) };
    std::cout << glGetString(GL_VERSION) << '\n';




    // define the vertex data
    float positions[6] = 
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    // generate 1 buffer and store its id in vertexBuffer
    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    // bind (select) the buffer to the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    // create and initialize the buffer's data store
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    // enable the vertex attribute array
    // set the index of the generic vertex attribute to 0
    glEnableVertexAttribArray(0);

    // specify the location and data format of the array of generic vertex attributes at index 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle that's curretly bound to the OpenGL state
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}
catch (...)
{
    handleException();
}