#include "game.h"
#include "graph.h"

int main(){
    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    vector<edge> edges = {
        {0,1,"Wake up?"}, {0,7,"Kill Yourself"}, {1,2,"Explore the prision?"}, {1,0,"Go back to sleep?"}, {2,3,"Fight against a wolf"}, {2,4,"Fight against a bear"},
        {2,5,"Fight against a chimp"}, {3,0,"Go back to the prision"}, {3,6,"You escaped the prision"}, {4,7,"You are dead"}, {5,7,"You are dead"}, {6,8,"Wanna play again?"},
        {7,8,"Wanna play again?"}
    };

    bool running = true;

    int n = 9;
    graph _graph(edges, n);

    //Initialize game object
    game _game;

    //Gameloop
    while(_game.running() && running){
        _game.update(); //Update game properties
        _game.render(); //Render game objects in window
        _graph.desicionMaking(_graph, nodeId);
        if(nodeId == 8){
            nodeId=0;
        }
    }

    //End of the program
    return 0;
}