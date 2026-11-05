struct Item_00243628 {
    int m_pad[5];
    virtual ~Item_00243628();
    virtual void V1();
    virtual bool V2();
};

extern "C" void* func_00240850();
extern "C" int func_0023BF98(void* o, int a);
extern "C" Item_00243628* func_0023BB50(void* o, int idx);

extern "C" bool func_00243628()
{
    void* o = func_00240850();
    if (!o)
        return false;
    int idx = func_0023BF98(o, 0);
    if (idx == -1)
        return false;
    Item_00243628* it = func_0023BB50(o, idx);
    if (!it)
        return false;
    return it->V2();
}
