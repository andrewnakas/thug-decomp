struct Node_001D0AA8 {
    char m_pad[0xC];
    char m_flag;
};

struct Obj_001D0AA8 {
    int m_0;
    int m_flag;
    int m_8;
    void* m_tree;
};

extern "C" bool func_001D0850(Obj_001D0AA8* self, int id);
extern "C" bool func_001D0820(Obj_001D0AA8* self, int key);
extern "C" void func_001D09B0(Obj_001D0AA8* self, int id, int start, int count);
extern "C" Node_001D0AA8* func_001D0E90(void* tree, int* key, int create);
extern "C" bool func_001D0708(Obj_001D0AA8* self, int id, int a, int b, int flag, int c, int d, int e);

bool Obj_001D0AA8_Add(Obj_001D0AA8* self, int id, int start, int count, int a, int b)
{
    if (func_001D0850(self, id)) {
        if (start) {
            int end = start + count;
            if (!func_001D0820(self, end)) {
                func_001D09B0(self, id, end, count);
                int key = end;
                func_001D0E90(self->m_tree, &key, 1)->m_flag = self->m_flag;
                return true;
            }
        }
        return false;
    }
    if (!func_001D0708(self, id, a, b, self->m_flag, 0, 0, 0)) {
        return false;
    }
    if (start) {
        int end = start + count;
        if (!func_001D0820(self, end)) {
            func_001D09B0(self, id, end, count);
        }
    }
    return true;
}
