struct Node_00182E60 { char pad[0xC]; Node_00182E60* m_next; Node_00182E60* m_prev; };
struct Item_00182E60 { char pad[0x10]; Node_00182E60* m_node; };
struct Obj_00182E60 { void Remove(Item_00182E60* it); };
void Obj_00182E60::Remove(Item_00182E60* it) {
    Node_00182E60* n = it->m_node;
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
    n->m_next = n;
    n->m_prev = n;
}
