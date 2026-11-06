struct Item_00149F18 {
    int m_0;
    int m_4;
    virtual ~Item_00149F18();
};

extern "C" bool func_00149F18(void* self, Item_00149F18* item)
{
    if (item) delete item;
    return true;
}
