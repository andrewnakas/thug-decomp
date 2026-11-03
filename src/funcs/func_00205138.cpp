struct Cam_00205138 {
    char pad[0x3C];
    float m_near;
    float m_mid;
    float m_far;
    float m_max;
};

struct Skater_00205138 {
    char pad[0x31C];
    int m_local;
    int m_id;
};

extern void* D_00392068;

extern "C" void func_00204900(Skater_00205138* self);
extern "C" bool func_00215F50(int a, int b);
extern "C" char* func_002A39E0(void* net, int id);
extern "C" void func_001FBF60(void* dispatcher, int msg, int (*handler)(void*, void*), int a, void* data, int b);
extern "C" Cam_00205138* func_00185578(void* self, unsigned int name);
extern "C" int func_0023AB80(void*, void*);
extern "C" int func_00279978(void*, void*);
extern "C" int func_002795B0(void*, void*);
extern "C" int func_002738E8(void*, void*);

void Init_00205138(Skater_00205138* self)
{
    func_00204900(self);
    void* net = D_00392068;
    if (self->m_local && func_00215F50(0, 0)) {
        void* d = func_002A39E0(net, self->m_id) + 4;
        func_001FBF60(d, 0x3B, func_0023AB80, 0, self, 0x80);
        func_001FBF60(d, 0x44, func_00279978, 0, self, 0x80);
        func_001FBF60(d, 0x43, func_00279978, 0, self, 0x80);
        func_001FBF60(d, 0x85, func_002795B0, 0, self, 0x80);
        func_001FBF60(d, 0x84, func_002795B0, 0, self, 0x80);
        func_001FBF60(d, 0x4B, func_002738E8, 0, self, 0x80);
    }
    Cam_00205138* cam = func_00185578(self, 0xCE0CA665);
    if (cam) {
        cam->m_near = 3000.0f;
        cam->m_mid = 5000.0f;
        cam->m_far = 10000000.0f;
        cam->m_max = 10000000.0f;
    }
}
