struct Item_0023AFE8;
struct Arr_0023AFE8 {
    int m0;
    Item_0023AFE8** m4;
    Item_0023AFE8* Get(int i);
};

Item_0023AFE8* Arr_0023AFE8::Get(int i)
{
    return m4[i];
}
