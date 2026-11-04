struct Obj_00115EC8 {
    char pad0[0xC];
    void* m_data;
    void* m_file;
    char pad14[0x2C - 0x14];
    int m_crc;
    char pad30[0x40 - 0x30];
    unsigned int m_flags;
};

extern char D_003891E8[];

extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00104418(char* s);
extern "C" int func_00105520(const char* s);
extern "C" int func_0010EC50();
extern "C" void* func_0010EC78(const char* name, bool block, int prio);
extern "C" int func_0010E558(void* f);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010E548(void* f, void (*cb)(), Obj_00115EC8* self, int arg);
extern "C" int func_0010E698(void* f, void* buf, int size, int count);
extern "C" void func_00116070();
extern "C" void* func_0010DAB0(const char* name);
extern "C" int func_0010DD60(const char* name);
extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" long func_00110980(void* f);
extern "C" int func_00110F68(void* buf, int size, int count, void* f);
extern "C" void func_0010BEB8(void* p);
extern "C" int func_00110EF8(void* f);
extern "C" int func_001160A0(Obj_00115EC8* self, int arg, int size, int);

extern "C" int func_00115EC8(Obj_00115EC8* self, const char* name, int arg, bool async, bool preloaded)
{
    char buf[0x100];
    char copy[0x100];
    int size;
    func_00331A9C(buf, name);
    func_00104418(buf);
    self->m_crc = func_00105520(buf);
    func_00331A9C(copy, name);
    if (!func_0010EC50()) {
        async = false;
    }
    if (async) {
        self->m_file = func_0010EC78(name, !async, 100);
        if (!self->m_file) {
            return 0;
        }
        int len = func_0010E558(self->m_file);
        self->m_data = func_0010BDE0(len);
        func_0010E548(self->m_file, func_00116070, self, arg);
        func_0010E698(self->m_file, self->m_data, 1, len);
        return 1;
    }
    if (preloaded) {
        self->m_data = func_0010DAB0(name);
        size = func_0010DD60(name);
        self->m_flags |= 0x40000;
    } else {
        void* f = func_00110E38(name, D_003891E8);
        if (!f) {
            return 0;
        }
        size = func_00110980(f);
        self->m_data = func_0010BDE0(size);
        if (!func_00110F68(self->m_data, 1, size, f)) {
            func_0010BEB8(self->m_data);
            self->m_data = 0;
            func_00110EF8(f);
            return 0;
        }
        func_00110EF8(f);
    }
    return func_001160A0(self, arg, size, 1);
}
