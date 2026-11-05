struct Obj_0023C4F8 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023C040(Obj_0023C4F8* o);
extern "C" void* func_00243C18(void* table, int* idx, int* out);
extern "C" int func_00246740(void* p);
extern "C" void func_00248800(void* p, unsigned int crc);

extern "C" void func_0023C4F8(Obj_0023C4F8* o)
{
    int i = 0;
    int tmp;
    while (i < func_0023C040(o)) {
        void* p = func_00243C18(o->m_table, &i, &tmp);
        if (func_00246740(p))
            func_00248800(p, 0x398B1B8B);
        i++;
    }
}
