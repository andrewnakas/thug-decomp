struct Item_0023EE50;
struct List_0023EE50;
struct Obj_0023EE50;
extern "C" int func_0023C040(Obj_0023EE50* self);
extern "C" Item_0023EE50* func_00243C18(List_0023EE50* list, int* idx, int* out);
extern "C" bool func_00246D70(Item_0023EE50* it);
extern "C" int func_00246258(Item_0023EE50* it);

struct Obj_0023EE50 {
    int m0;
    char m4[4];
    int Find();
};

int Obj_0023EE50::Find()
{
    int n = func_0023C040(this);
    int tmp;
    for (int i = 0; i < n; i++) {
        Item_0023EE50* it = func_00243C18((List_0023EE50*)m4, &i, &tmp);
        if (func_00246D70(it))
            return func_00246258(it);
    }
    return 0;
}
