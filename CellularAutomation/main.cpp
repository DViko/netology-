#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

//g++ main.cpp -o exec

struct GameState
{
    int rows { 0 }, cols { 0 }, generation { 0 },
             alive_total { 0 }, stagnation { 0 };
    char** matrix { nullptr },
        ** buffer { nullptr };
};

constexpr int DIRECTIONS[8][2]
{
    { -1,  0 }, {  1,  0 }, { 0, -1 }, { 0,  1 },
    { -1, -1 }, { -1,  1 }, { 1, -1 }, { 1,  1 }
};

bool    CreateInitialStateFromFile(GameState& game, const char* path_to_file);
bool    CreateGameState(GameState& game);
int     LookingForNeighbors(GameState& game, int r_current, int c_current);
void    UpdateGameState(GameState& game);
void    UpgradeGameState(GameState& game);
void    DisplayGame(GameState& game);
void    DeleteGameState(GameState& game);

int main()
{
    GameState game { 0, 0, 0, -1, 0 };

    if (!CreateInitialStateFromFile(game, "game_state.txt"))
    {
        DeleteGameState(game);
        
        std::cerr << "Failed to load game state\n";
        return EXIT_FAILURE;
    }

    while (true)
    {
        game.generation ++;

        UpdateGameState(game);
        UpgradeGameState(game);
        DisplayGame(game);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    DeleteGameState(game);
    return EXIT_SUCCESS;
}

bool CreateGameState(GameState& game)
{
    try
    {
        game.matrix = new char* [game.rows]();
        game.buffer = new char* [game.rows]();

        for (int row {}; row < game.rows; row ++)
        {
            game.matrix[row] = new char [game.cols]();
            game.buffer[row] = new char [game.cols]();
        }
    }
    catch (const std::bad_alloc& error)
    {
        std::cout << "Memory allocation failed!: " << error.what();
        return false;
    }

    return true;
}

bool  CreateInitialStateFromFile(GameState& game, const char* file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << file_name << "\n";
        return false;
    }

    file >> game.rows >> game.cols;

    if (!CreateGameState(game))
    {
        return false;
    }

    int file_row {}, file_col {};

    while (file >> file_row >> file_col)
    {
        if (file_row >= 0 && file_row < game.rows && file_col >= 0 && file_col < game.cols)
        {
            game.matrix[file_row][file_col] = 1;
        }
    }

    file.close();
    return true;
}

int LookingForNeighbors(GameState& game, int r_current, int c_current)
{
    int total {};

    for (int i {}; i < 8; i ++)
    {
        total += game.matrix[(r_current + DIRECTIONS[i][0] + game.rows) % game.rows]
                            [(c_current + DIRECTIONS[i][1] + game.cols) % game.cols];
    }

    return total;
}

void UpdateGameState(GameState& game)
{   
    int alive_total {};

    for (int row {}; row < game.rows; row ++)
    {
        for (int col {}; col < game.cols; col ++)
        {
            int total { LookingForNeighbors(game, row, col) };

            if (game.matrix[row][col])
            {
                game.buffer[row][col] = (total == 2 || total == 3);
            }
            else
            {
                game.buffer[row][col] = (total == 3);
            }

            if (game.buffer[row][col])
            {
                alive_total ++;
            }
        }
    }

    if(game.alive_total == alive_total)
    {
        game.stagnation ++;
    }
    else
    {
        game.stagnation = 0;
    }
    game.alive_total = alive_total;
}

void UpgradeGameState(GameState& game)
{
    for (int row {}; row < game.rows; row ++)
    {
        for (int col {}; col < game.cols; col ++)
        {
            game.matrix[row][col] = game.buffer[row][col];
        }
    }
}

void DisplayGame(GameState& game)
{
    for (int row {}; row < game.rows; row ++)
    {
        for (int col {}; col < game.cols; col ++)
        {
            std::cout << (game.matrix[row][col] ? '*' : '-');
        }

        std::cout << '\n';
    }

    std::cout << "Generation: " << game.generation << " Alive Cells: " << game.alive_total << '\n';

    if (game.stagnation >= 5)
    {
        DeleteGameState(game);

        std::cout << "The world has stagnated. Game over.\n";
        std::exit(EXIT_SUCCESS);
    }
    if (game.alive_total == 0)
    {
        DeleteGameState(game);

        std::cout << "All cells are dead. Game over.\n";
        std::exit(EXIT_SUCCESS);
    }
}

void DeleteGameState(GameState& game)
{
    if (game.matrix)
    {
        for (int row {}; row < game.rows; row ++)
        {
            delete[] game.matrix[row];
        }

        delete[] game.matrix;
        game.matrix = nullptr;
    }

    if (game.buffer)
    {
        for (int row{}; row < game.rows; row ++)
        {
            delete[] game.buffer[row];
        }

        delete[] game.buffer;
        game.buffer = nullptr;
    }
}

//ToDo: Сreate a function that will write statistics and history to file