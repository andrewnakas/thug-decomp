// Interrupt handler for an incoming message: finds the slot for the message id, copies the payload into the
// owner's buffer and, when the message completes it, hands the buffer to the owner's handler.

struct Msg_00112048 {
    char pad00[0xC];
    int m_id;
    int m_arg;
    int m_final;
    char pad18[0x20 - 0x18];
    int m_len;
};

struct Handler_00112048 {
    char pad00[0x38];
    virtual void Unused();
    virtual void OnMessage(void* buf, int arg, Msg_00112048* msg);
};

struct Slot_00112048 {
    Handler_00112048* m_owner;
    int m_id;
    int m8;
    volatile int m_final;
    int m_arg;
};

extern "C" Slot_00112048* func_00112128(int id);
extern "C" void func_001113B0(Handler_00112048* owner, Msg_00112048* msg, int atEnd);
extern "C" void* func_00111518(Handler_00112048* owner, int id);
extern "C" void func_00111598(Handler_00112048* owner, int id);

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

extern "C" void func_00112048(Msg_00112048* msg)
{
    int id = msg->m_id;
    Slot_00112048* s = func_00112128(id);
    s->m_arg = msg->m_arg;
    s->m_final = msg->m_final != 0;
    if (s->m_owner) {
        if (msg->m_len > 0) {
            func_001113B0(s->m_owner, msg, s->m_final);
        }
        if (s->m_final) {
            Handler_00112048* h = s->m_owner;
            h->OnMessage(func_00111518(h, id), s->m_arg, msg);
            func_00111598(s->m_owner, id);
        }
    }
    ExitHandler();
}
