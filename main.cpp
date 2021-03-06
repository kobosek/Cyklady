#include <vector>
#include <memory>
#include <iostream>

#include "ControlBoard.hpp"
#include "Types.hpp"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

using namespace Cyclades;


int main(int argc, char **argv)
{
//    QApplication app(argc, argv);

//    QGraphicsScene scene;

//    QGraphicsView view(&scene);

//    QGraphicsPixmapItem item(QPixmap("./Cyclades-TheGods.jpg"));

//    scene.addItem(&item);

//    view.show();

//    return app.exec();

    try
    {
        ControlBoard l_controlBoard(NumberOfPlayers::Three);

        //FOR TESTING PURPOSES RANDOMIZE 10 times for four players
        for (int i = 0; i < 10; ++i)
        {
            l_controlBoard.printCreatures();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
}
