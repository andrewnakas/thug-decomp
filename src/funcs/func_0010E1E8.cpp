extern "C" char* func_00109828(void*, const char*, int*, char*);
extern "C" int func_0010FEC0(const char*);
extern "C" char* func_0010BDE0(int);
extern "C" int func_0010FF18(const char*, char*);
extern "C" void func_0010BEB8(char*);
extern "C" void* func_00110E38(const char*, const char*);
extern "C" long func_00110980(void*);
extern "C" int func_00110F68(char*, int, int, void*);
extern "C" int func_00110EF8(void*);
extern "C" void func_0010BE88(int, char*);
extern void* D_00388A44;
extern char D_00388C58[];

char* func_0010E1E8(const char* name, int* sizeOut, char* buf)
{
    int size = 0;
    char* data = func_00109828(D_00388A44, name, &size, buf);
    if (!data) {
        size = func_0010FEC0(name);
        if (size) {
            if (!buf)
                data = func_0010BDE0((size + 0x7FF) & ~0x7FF);
            else
                data = buf;
            if (!func_0010FF18(name, data)) {
                if (!buf)
                    func_0010BEB8(data);
                data = 0;
            }
        } else {
            void* f = func_00110E38(name, D_00388C58);
            size = func_00110980(f);
            if (!buf)
                data = func_0010BDE0((size + 0x7FF) & ~0x7FF);
            else
                data = buf;
            func_00110F68(data, 1, size, f);
            func_00110EF8(f);
        }
        if (!buf && data)
            func_0010BE88(size, data);
    }
    if (sizeOut)
        *sizeOut = size;
    return data;
}
