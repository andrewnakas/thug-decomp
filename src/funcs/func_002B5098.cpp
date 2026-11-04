extern char D_00379E70[];

struct Item_002B5098 {
    char pad[0xAC];
    int mAC;
};

struct LNode_002B5098 {
    int m0;
    Item_002B5098* m_data;
    int m8;
    LNode_002B5098* m_next;
    Item_002B5098* Data() { return m_data; }
    LNode_002B5098* Next() {
        LNode_002B5098* n = m_next;
        if (n->m_data == (Item_002B5098*)-1) {
            return 0;
        }
        return n;
    }
};

struct Iter_002B5098 {
    int m0;
    LNode_002B5098* m_cur;
    void* m8;
    Iter_002B5098() { m8 = D_00379E70; }
    ~Iter_002B5098() { m8 = D_00379E70; }
};

struct List_002B5098 {
    LNode_002B5098 m_head;
    Item_002B5098* First(Iter_002B5098* it) {
        it->m_cur = &m_head;
        it->m_cur = it->m_cur->Next();
        Item_002B5098* r;
        if (!it->m_cur) {
            r = 0;
        } else {
            r = it->m_cur->m_data;
        }
        return r;
    }
    Item_002B5098* Next(Iter_002B5098* it) {
        it->m_cur = it->m_cur->Next();
        if (it->m_cur) {
            return it->m_cur->Data();
        }
        return 0;
    }
};

struct Obj_002B5098 {
    char pad[0x124];
    List_002B5098 m_list;
    Item_002B5098* Find(int id);
};

extern "C" int func_002A1A28(Obj_002B5098* o);

Item_002B5098* Obj_002B5098::Find(int id)
{
    Iter_002B5098 it;
    for (Item_002B5098* p = m_list.First(&it); p; p = m_list.Next(&it)) {
        if (func_002A1A28(this)) {
            if (id == p->mAC)
                return p;
        } else if ((Item_002B5098*)id == p) {
            return p;
        }
    }
    return 0;
}
