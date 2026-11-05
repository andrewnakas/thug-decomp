struct Table_002DBB48 {
    int m0;
};

extern "C" void func_002DBB40(void* p);

void func_002DBB48(Table_002DBB48* t, void* a)
{
    if (t && t->m0)
        func_002DBB40(a);
}
