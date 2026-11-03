struct Array_0023FFF8 {
    int pad[3];
    unsigned int m_size;
};

struct Mgr_0023FFF8 {
    int m0;
    char m4[1];
};

extern "C" int func_0023C040(Mgr_0023FFF8* self);
extern "C" void* func_00243C18(void* list, int* index, unsigned int* key);
extern "C" void* func_00244528(void* goal);
extern "C" bool func_001E8248(void* self, unsigned int name, Array_0023FFF8** out, int assert_);
extern "C" unsigned int func_001E9300(void* self, int index);
extern "C" void* func_00229668(unsigned int id, int v);
extern "C" void func_00211410(void* self);

void func_0023FFF8(Mgr_0023FFF8* self)
{
    int i;
    unsigned int key;
    Array_0023FFF8* nodes;

    for (i = 0; i < func_0023C040(self); i++) {
        void* goal = func_00243C18(self->m4, &i, &key);
        if (func_001E8248(func_00244528(goal), 0xF4EB5C60, &nodes, 0)) {
            unsigned int j = 0;
            if (nodes->m_size) {
                do {
                    func_00211410(func_00229668(func_001E9300(nodes, j), 1));
                    j++;
                } while (j < nodes->m_size);
            }
        }
    }
}
