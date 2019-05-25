#include "Window.h"

class InnerWindow : public Window {
    protected:
        struct Dimmensions {
            unsigned short int posX;
            unsigned short int posY;
            unsigned short int sizeX;
            unsigned short int sizeY;
        } winDimm;
    private:
        /* Creates the matrix */
        virtual void makeDrawingMatrix()=0;
        /* Sets window dimmension based of the text object */
        virtual void setDimmensions()=0;
    public:
        /* Adds a text object to the window */
        virtual void addText()=0;
        /* Clears the window's content */
        virtual void clear()=0;
};
