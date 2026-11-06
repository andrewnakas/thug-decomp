struct Node_00185578 { int m_0; int m_id; char pad[8]; Node_00185578* m_next; };
struct Obj_00185578 { char pad[0x100]; Node_00185578* m_head; Node_00185578* Find(int id); };
Node_00185578* Obj_00185578::Find(int id) { for (Node_00185578* p = m_head; p; p = p->m_next) if (p->m_id == id) return p; return 0; }
