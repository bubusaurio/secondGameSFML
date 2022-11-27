#include "graph.h"

void graph::desicionMaking(graph const &graph, int i){
    int counter = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for (Pair v: graph.adjList[i]) {
        if(counter==0){
            p1.first = v.first;
            text1 = v.second;
            flag1 = 1;
        }
        if(counter==1){
            p2.first = v.first;
            text2 = v.second;
            flag2 = 1;
        }
        if(counter==2){
            p3.first = v.first;
            text3 = v.second;
            flag3 = 1;
        }
        buttonCount = flag1 + flag2 + flag3;
        counter++;
    }

    // if((flag1 && flag2) || (flag1 && flag3) || (flag2 && flag3)){
    //      cin >> desicion;
    // }  
    if(optionClicked){
        if(buttonDesicion == 0){
            nodeId = p1.first;
        }
        if(buttonDesicion == 1){
            nodeId = p2.first;
        }
        if(buttonDesicion == 2){
            nodeId = p3.first;
        }
    }
    optionClicked = false;
}