struct Item_0014C898;
extern "C" void func_0013C618(Item_0014C898* it, int a);

struct List_0014C898 {
    char pad[0x10];
    Item_0014C898* m10[104];
    short m1B0;
    short m1B2;
    void ForAll(int a);
};

void List_0014C898::ForAll(int a)
{
    for (int i = 0; i < m1B2; i++) func_0013C618(m10[i], a);
}
