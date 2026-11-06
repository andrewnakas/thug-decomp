struct Ent_001A2C98 { int m_id; char pad[0xEC]; };
struct Obj_001A2C98 { char pad[0x60]; int m_count; Ent_001A2C98* m_ents; Ent_001A2C98* Find(int id); };
Ent_001A2C98* Obj_001A2C98::Find(int id) { for (int i = 0; i < m_count; i++) { Ent_001A2C98* p = &m_ents[i]; if (id == p->m_id) return p; } return 0; }
