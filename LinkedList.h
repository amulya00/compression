
struct List {
    int pos;
    List *next;
    List(){
        pos = -1;
        next = NULL;
    }
    List(int pos){
        this->pos = pos;
        next = NULL;
    }
};

