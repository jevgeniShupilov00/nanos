#include <runtime.h>
#include <x86_64.h>
#include <elf64.h>
#include <closure.h>
#include <closure_templates.h>

typedef closure_type(buffer_handler, void, buffer);

static node resolve(buffer n, symbol s)
{
}

static vector node_vector(heap h, buffer n)
{
    vector r = allocate_vector(h, 100); //table_elements(n));
    little_stack_buffer (ind, 30);
    void *x;
    
    for (int i = 0; format_number(ind, i, 10, 1), x = resolve(n, intern(ind)); buffer_clear(ind), i++) 
        vector_push(r, x);
    
    return x;
}

static tuple resolve_path(tuple n, vector v)
{
    buffer i;
    // xx destructive, relative
    vector_pop(v);
    vector_foreach(i, v) {
        tuple c = table_find(n, sym(children));
        n = table_find(c, intern(i));
    }
    return n;
}

void bprintf(buffer b, char *fmt, ...);
// belongs somewhere else?
void storage_read(void *target, u64 offset, u64 size, thunk complete);


static inline void haltf(char *f, ...)
{
    buffer bf = alloca_wrap_buffer(f, runtime_strlen(f));
    little_stack_buffer(b, 2048);
    vlist ap;
    vstart (ap, f);
    vbprintf(b, bf,  ap);
    debug(b->contents);
    QEMU_HALT();
}

// xxx - platform features that use closures in stage3 that cant
// be exposed to stage2
typedef closure_type(fault_handler, void, context);
void configure_timer(time rate, thunk t);