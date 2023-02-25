//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//
//class Map 
//{
//public :
//	const int width = 32;
//	const int height = 20;
//	const char wallSymbol = '#';
//	
//	void DrawWall()
//	{
//		std::cout << wallSymbol;
//	}
//	// Later would like to make it that the map class itself is responsible for its border logic. Likw whether to wrap around the map or kill the snake
//	/*void borderLogic() 
//	{
//
//	}*/
//};
//
//enum Direction 
//{
//	LEFT, 
//	RIGHT, 
//	UP, 
//	DOWN
//};
//
//class Snake 
//{
//private:
//	const char headSymbol = 'O';
//	const char bodySymbol = 'o';
//
//	void moveBody()
//	{
//		int prevX = x;
//		int prevY = y;
//
//		int prev2X;
//		int prev2Y;
//
//		for (int i = 0; i < nBody; i++)
//		{
//			prev2X = bodyX[i];
//			prev2Y = bodyY[i];
//			bodyX[i] = prevX;
//			bodyY[i] = prevY;
//			prevX = prev2X;
//			prevY = prev2Y;
//		}
//	}
//
//	void elongate()
//	{
//		nBody++;
//	}
//
//public:
//	Direction dir;
//	int x;
//	int y;
//	int bodyX[100];
//	int bodyY[100];
//	int nBody;
//
//	Snake()
//	{
//		x = 15;
//		y = 10;
//		nBody = 0;
//	}
//
//	bool checkForBodyCollision()
//	{
//		for (int i = 0; i < nBody; i++)
//		{
//			if (x == bodyX[i] && y == bodyY[i])
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	void Consume()
//	{
//		//Different food types will have different effects maybe one day in the future
//		elongate();
//	}
//
//	void move()
//	{
//		moveBody();
//
//		switch (dir)
//		{
//		case LEFT:
//			x--;
//			break;
//		case RIGHT:
//			x++;
//			break;
//		case UP:
//			y--;
//			break;
//		case DOWN:
//			y++;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//	void DrawHead() 
//	{
//		std::cout << headSymbol;
//	}
//
//	void DrawBody()
//	{
//		std::cout << bodySymbol;
//	}
//};
//
//class Fruit 
//{
//private:
//	const char fruitSymbol = 'F';
//
//public:
//	int x;
//	int y;
//
//	Fruit()
//	{
//
//	}
//
//	void Draw()
//	{
//		std::cout << fruitSymbol;
//	}
//};
//
//class Game
//{
//public:
//	bool gameEnded = false;
//	Snake snake;
//	Fruit fruit;
//	Map map;
//	void Logic();
//	void Draw();
//	void Input();
//
//	Game()
//	{
//		fruit.x = (rand() % (map.width - 2)) + 1;
//		fruit.y = (rand() % (map.height - 2)) + 1;
//	}
//};
//
//
//void Game::Draw() 
//{
//	system("cls");
//
//	for (int i = 0; i < map.height; i++)
//	{
//		for (int u = 0; u < map.width; u++)
//		{
//			bool isTailSquare = false;
//			for (int j = 0; j < snake.nBody; j++)
//			{
//				if (snake.bodyX[j] == u && snake.bodyY[j] == i)
//				{
//					isTailSquare = true;
//					break;
//				}
//			}
//
//			if (i == 0 || u == 0 || i == map.height - 1 || u == map.width - 1)
//			{
//				map.DrawWall();
//			}
//			else if (snake.x == u && snake.y == i)
//			{
//				snake.DrawHead();
//			}
//			else if (fruit.x == u && fruit.y == i)
//			{
//				fruit.Draw();
//			}
//			else if (isTailSquare)
//			{
//				snake.DrawBody();
//			}
//			else
//			{
//				std::cout << ' ';
//			}
//		}
//		std::cout << std::endl;
//	}
//	std::cout << "Fruit coords: " << fruit.x << "; " << fruit.y << std::endl;
//	std::cout << "Snake coords: " << snake.x << "; " << snake.y << std::endl;
//	std::cout << "Body length: " << snake.nBody << std::endl;
//}
//
//void Game::Input()
//{
//	if (_kbhit())
//	{
//		switch (_getch())
//		{
//		case 'a':
//			snake.dir = LEFT;
//			break;
//		case 's':
//			snake.dir = DOWN;
//			break;
//		case 'd':
//			snake.dir = RIGHT;
//			break;
//		case 'w':
//			snake.dir = UP;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void Game::Logic()
//{
//	snake.move();
//
//	if (snake.x < 1) {snake.x = map.width - 2;}
//	else if (snake.x > map.width - 2) { snake.x = 1; }
//
//	if (snake.y < 1) { snake.y = map.height - 2; }
//	else if (snake.y > map.height - 2) { snake.y = 1; }
//
//	gameEnded = snake.checkForBodyCollision();
//
//	// Fruit spawing. NOTE: should check that the fruits coords are not on the snake
//	if (snake.x == fruit.x && snake.y == fruit.y)
//	{
//		snake.Consume();
//
//		fruit.x = (rand() % (map.width - 2)) + 1;
//		fruit.y = (rand() % (map.height - 2)) + 1;
//	}
//}
//
//int main()
//{
//	Game game;
//
//	while (!game.gameEnded)
//	{
//		game.Draw();
//		game.Input();
//		game.Logic();
//		Sleep(300);
//	}
//
//	std::cout << "Game Over" << std::endl;
//}

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
    GLenum severity, GLsizei length,
    const GLchar* msg, const void* data)
{
    std::string _source;
    std::string _type;
    std::string _severity;

    switch (source) {
    case GL_DEBUG_SOURCE_API:
        _source = "API";
        break;

    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        _source = "WINDOW SYSTEM";
        break;

    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        _source = "SHADER COMPILER";
        break;

    case GL_DEBUG_SOURCE_THIRD_PARTY:
        _source = "THIRD PARTY";
        break;

    case GL_DEBUG_SOURCE_APPLICATION:
        _source = "APPLICATION";
        break;

    case GL_DEBUG_SOURCE_OTHER:
        _source = "UNKNOWN";
        break;

    default:
        _source = "UNKNOWN";
        break;
    }

    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        _type = "ERROR";
        break;

    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        _type = "DEPRECATED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        _type = "UDEFINED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_PORTABILITY:
        _type = "PORTABILITY";
        break;

    case GL_DEBUG_TYPE_PERFORMANCE:
        _type = "PERFORMANCE";
        break;

    case GL_DEBUG_TYPE_OTHER:
        _type = "OTHER";
        break;

    case GL_DEBUG_TYPE_MARKER:
        _type = "MARKER";
        break;

    default:
        _type = "UNKNOWN";
        break;
    }

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        _severity = "HIGH";
        break;

    case GL_DEBUG_SEVERITY_MEDIUM:
        _severity = "MEDIUM";
        break;

    case GL_DEBUG_SEVERITY_LOW:
        _severity = "LOW";
        break;

    case GL_DEBUG_SEVERITY_NOTIFICATION:
        _severity = "NOTIFICATION";
        break;

    default:
        _severity = "UNKNOWN";
        break;
    }

    std::cout << id << ": " << _type << " of " << _severity << " severity, raised from " << _source << ": " << msg << std::endl;

}

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& filePath)
{
    std::ifstream stream(filePath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDetachShader(program, vs);
    glDetachShader(program, fs);

    return program;
}

static float RotateXVertex(float x, float y)
{
    float result;
    float radian = 0.0349f;

    result = x * cos(radian) - y * sin(radian);

    return result;
}

static float RotateYVertex(float x, float y)
{
    float result;
    float radian = 0.0349f;

    result = x * sin(radian) + y * cos(radian);

    return result;
}

int main(void)
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

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        return -1;

    float test = -0.5f;
    float testIncrement = 0.05f;

    float positions[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    ShaderProgramSource source = ParseShader("Basic.shader");
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    _ASSERT(location != -1);
    glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f);

    float r = 0.0f;
    float increment = 0.05f;

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(GLDebugMessageCallback, NULL);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUniform4f(location, r, 0.3f, 0.8f, 1.0f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;

        r += increment;

        float oldX = positions[0];
        float oldY = positions[1];
        positions[0] = RotateXVertex(oldX, oldY);
        positions[1] = RotateYVertex(oldX, oldY);

        oldX = positions[2];
        oldY = positions[3];
        positions[2] = RotateXVertex(oldX, oldY);
        positions[3] = RotateYVertex(oldX, oldY);

        oldX = positions[4];
        oldY = positions[5];
        positions[4] = RotateXVertex(oldX, oldY);
        positions[5] = RotateYVertex(oldX, oldY);

        oldX = positions[6];
        oldY = positions[7];
        positions[6] = RotateXVertex(oldX, oldY);
        positions[7] = RotateYVertex(oldX, oldY);

        glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}