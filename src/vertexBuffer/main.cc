#include "main.ih"

int main(void)
try
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize glew
    if (glewInit() != GLEW_OK)
        throw std::runtime_error{ "not GLEW_OK" };

    std::cout << glGetString(GL_VERSION) << '\n';




    // generate 1 buffer and store its id in vertexBuffer
    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    // bind (select) the buffer to the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    // define the vertex data
    float positions[6] = 
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    // create and initialize the buffer's data store
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    // enable the vertex attribute array
    glEnableVertexAttribArray(0);

    // specify the location and data format of the array of generic vertex attributes at index 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
catch (...)
{
    handleException();
}