struct Node_0011A608 {
    char pad0[0xC];
    Node_0011A608* m_next;
    Node_0011A608* m_prev;
};

struct Owner_0011A608 {
    char pad0[0x64];
    Node_0011A608 m_list;
};

struct Comp_0011A608 {
    char pad0[0x4C];
    void* m_script;
};

struct Array_0011A608 {
    char pad0[0xC];
    unsigned int m_size;
};

extern "C" void* func_0011AB18(Owner_0011A608* self);
extern "C" Comp_0011A608* func_00185578(void* obj, unsigned int crc);
extern "C" void* func_001E5548(void* script, int);
extern "C" int func_001E8248(void* s, unsigned int name, Array_0011A608** out, int);
extern "C" void* func_001E9378(Array_0011A608* a, int i);
extern "C" int func_001E7DE8(void* s, unsigned int name, int* out, int);
extern "C" int func_001E7EB0(void* s, unsigned int name, float* out, int);
extern "C" int func_001E8398(void* s, unsigned int name, unsigned int* out, int);
extern "C" int func_001E8180(void* s, unsigned int name, int* out, int);
extern "C" void* func_001046B0(int size);
extern "C" Node_0011A608* func_00118B60(void* p, int frame, unsigned int name, int flags);
extern "C" int func_00118348(Node_0011A608* n, int);

extern "C" void func_0011A608(Owner_0011A608* self, unsigned int name)
{
    Array_0011A608* arr;
    Comp_0011A608* comp = func_00185578(func_0011AB18(self), 0x72AD7B23);
    if (!comp || !comp->m_script) {
        return;
    }
    void* script = func_001E5548(comp->m_script, 1);
    if (!script) {
        return;
    }
    if (!func_001E8248(script, name, &arr, 0)) {
        return;
    }
    unsigned int i = 0;
    if (arr->m_size) {
        do {
            void* s = func_001E9378(arr, i);
            int frame = 0;
            if (!func_001E7DE8(s, 0x4A07C332, &frame, 0)) {
                float t = 0.0f;
                func_001E7EB0(s, 0x906B67BA, &t, 1);
                frame = (int)(t * 60.0f);
            }
            unsigned int id;
            func_001E8398(s, 0xC451F558, &id, 1);
            int flags = 0;
            func_001E8180(s, 0x7031F10C, &flags, 0);
            Node_0011A608* head = &self->m_list;
            Node_0011A608* n = func_00118B60(func_001046B0(0x28), frame, id, flags);
            func_00118348(n, 1);
            n->m_prev = head->m_prev;
            n->m_next = head;
            head->m_prev->m_next = n;
            head->m_prev = n;
            i++;
        } while (i < arr->m_size);
    }
}
