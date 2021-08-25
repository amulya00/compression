#include "LinkedList.h"

struct HashTable
{
    List *Table[256][256];

    HashTable()
    {
        for (int i = 0; i < 256; ++i)
        {
            for (int j = 0; j < 256; ++j)
            {
                Table[i][j] = new List;
            }
        }
    }

    void AddNode(char a, char b, int pos)
    {
        List *head = Table[(int)a][(int)b];
        if (head == NULL)
        {
            Table[(int)a][(int)b] = new List(pos);
            return;
        }
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = new List(pos);
    }
    List *Search(char a, char b)
    {
        return Table[(int)a][(int)b];
    }
};
