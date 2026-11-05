struct Link_0023FF48 {
    int m0;
};

struct Item_0023FF48 {
    char pad[0x2C];
    Link_0023FF48* m_2C;
    Link_0023FF48* m_30;
};

struct Mgr_0023FF48 {
    bool Check(unsigned int key, void* name);
};

extern "C" Item_0023FF48* func_0023BB00(Mgr_0023FF48* self, void* name, int create);

bool Mgr_0023FF48::Check(unsigned int key, void* name)
{
    Item_0023FF48* item;
    switch (key) {
    case 0x3AE9211B:
        item = func_0023BB00(this, name, 1);
        if (!item) {
            return false;
        }
        return item->m_30->m0 == 0;
    case 0xD782F8DE:
        item = func_0023BB00(this, name, 1);
        if (!item) {
            return false;
        }
        return item->m_2C->m0 == 0;
    }
    return false;
}
