
#ifndef AVL_SERVER_H
#define AVL_SERVER_H

class Server{
private:
    int ID;
    int OS;
    bool taken;
public:
    Server(int ID, int OS):ID(ID),OS(OS),taken(false){};
    int getID();
    int getOS();
    void setOS(int OS);
    bool getTaken();
    void setTaken(bool isTaken);
};

#endif //AVL_SERVER_H
