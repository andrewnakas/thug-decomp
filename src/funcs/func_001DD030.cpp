/* cflags: -fno-strength-reduce */
struct Entry_001DD030 {
    unsigned int m_name;
    int m_flags;
    float m_vol;
    float m_pitch;
    float m_dropoff;
    char m_data[0xC];
};

extern int D_0038881C;
extern int D_0038E0B0;
extern int D_0038E0B4;
extern Entry_001DD030 D_003E82F8[256];
extern Entry_001DD030 D_003EA2F8[256];

extern "C" bool func_001DC418();
extern "C" int func_00331BB8(const char* s);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001DCA18(void* self, unsigned int name);
extern "C" int func_001E5628(unsigned int key, int a);
extern "C" bool func_001E1AF8(const char* path, unsigned int name, char* data, int stream);

bool Call_001DD030(void* self, const char* path, int flags, float dropoff, float vol, float pitch)
{
    if (func_001DC418()) {
        return false;
    }
    const char* name = path;
    int len = func_00331BB8(path);
    for (int i = 0; i < len; i++) {
        if (path[i] == '\\' || path[i] == '/') {
            name = &path[i + 1];
        }
    }
    unsigned int crc = func_001F0D78(name);
    if (func_001DCA18(self, crc)) {
        if (!D_0038881C) {
            func_001E5628(0xD7BB618D, 0);
        }
        return false;
    }
    Entry_001DD030* e;
    if (flags & 1) {
        if (D_0038E0B4 >= 256) {
            return false;
        }
        e = &D_003E82F8[D_0038E0B4];
        if (!func_001E1AF8(path, crc, e->m_data, 1)) {
            return false;
        }
        D_0038E0B4++;
    } else {
        if (D_0038E0B0 >= 256) {
            return false;
        }
        e = &D_003EA2F8[D_0038E0B0];
        if (!func_001E1AF8(path, crc, e->m_data, 0)) {
            return false;
        }
        D_0038E0B0++;
    }
    e->m_dropoff = dropoff;
    e->m_vol = vol;
    e->m_pitch = pitch;
    e->m_name = crc;
    e->m_flags = flags;
    return true;
}
