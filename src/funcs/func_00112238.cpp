struct Stream_00112238 {
    char pad0[0x10];
    int m_10;
};

struct Request_00112238 {
    char pad0[0xC];
    int m_id;
};

struct Slot_00112238 {
    Stream_00112238* m_stream;
    int m_id;
    int m_result;
    int m_C;
    int m_10;
};

extern int D_00388E74;
extern int D_00388E70;
extern Slot_00112238 D_00464DD0[];

extern "C" Slot_00112238* func_00112128(int id);
extern "C" int func_00112340(int id);
extern "C" int func_00111428(Stream_00112238* s, int id, int arg, Request_00112238* req);
extern "C" int func_0031D2E8(int cmd, void* data, int size, void* out, int outSize, void* cb);

static inline int Wrap_00112238(int i) { return i % 64; }

extern "C" int func_00112238(Request_00112238* req, Stream_00112238* s, int wait, int id)
{
    Slot_00112238* slot;
    if (id >= 0) {
        slot = func_00112128(id);
        func_00112340(slot->m_id);
    } else {
        int idx = D_00388E74;
        int newId = D_00388E70;
        D_00388E74 = Wrap_00112238(idx + 1);
        D_00388E70 = newId + 1;
        slot = &D_00464DD0[idx];
        slot->m_C = 0;
        slot->m_id = newId;
        slot->m_stream = s;
        if (s) {
            func_00111428(s, newId, s->m_10, req);
        }
        req->m_id = newId;
    }
    slot->m_result = func_0031D2E8(1, req, 0x70, 0, 0, 0);
    if (wait) {
        func_00112340(slot->m_id);
    }
    return slot->m_id;
}
