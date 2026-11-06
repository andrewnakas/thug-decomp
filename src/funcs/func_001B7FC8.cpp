struct Mgr_001B7FC8 { char pad[0x2C]; virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4(int id, int t); };
extern Mgr_001B7FC8* D_0038C608;
struct Obj_001B7FC8 { char pad[0xC]; int m_C; void Go(); };
void Obj_001B7FC8::Go() { D_0038C608->V4(m_C, -1000); }
