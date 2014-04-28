struct cmp_ctx_s;

typedef bool   (*cmp_reader)(struct cmp_ctx_s *ctx, void *data, size_t limit);
typedef size_t (*cmp_writer)(
  struct cmp_ctx_s *ctx, const void *data, size_t count
);

struct cmp_ctx_s {
  uint8_t     error;
  void       *buf;
  cmp_reader  read;
  cmp_writer  write;
};

union cmp_object_data_u {
  bool     boolean;
  uint8_t  u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;
  int8_t   s8;
  int16_t  s16;
  int32_t  s32;
  int64_t  s64;
  float    flt;
  double   dbl;
  uint64_t array_size;
  uint64_t map_size;
  uint64_t str_size;
};

struct cmp_object_s {
  uint8_t type;
  union cmp_object_data_u as;
};

typedef struct cmp_ctx_s cmp_ctx_t;
typedef struct cmp_object_s cmp_object_t;

void cmp_init(struct cmp_ctx_s *ctx, void *buf, cmp_reader read,
                                                cmp_writer write);

uint32_t    cmp_version(void);
const char* cmp_strerror(struct cmp_ctx_s *ctx);

bool cmp_write_pfix(struct cmp_ctx_s *ctx, uint8_t c);
bool cmp_write_nfix(struct cmp_ctx_s *ctx, int8_t c);

bool cmp_write_sfix(struct cmp_ctx_s *ctx, int8_t c);
bool cmp_write_s8(struct cmp_ctx_s *ctx, int8_t c);
bool cmp_write_s16(struct cmp_ctx_s *ctx, int16_t s);
bool cmp_write_s32(struct cmp_ctx_s *ctx, int32_t i);
bool cmp_write_s64(struct cmp_ctx_s *ctx, int64_t l);
bool cmp_write_sint(struct cmp_ctx_s *ctx, int64_t d);

bool cmp_write_ufix(struct cmp_ctx_s *ctx, uint8_t c);
bool cmp_write_u8(struct cmp_ctx_s *ctx, uint8_t c);
bool cmp_write_u16(struct cmp_ctx_s *ctx, uint16_t s);
bool cmp_write_u32(struct cmp_ctx_s *ctx, uint32_t i);
bool cmp_write_u64(struct cmp_ctx_s *ctx, uint64_t l);
bool cmp_write_uint(struct cmp_ctx_s *ctx, uint64_t u);

bool cmp_write_float(struct cmp_ctx_s *ctx, float f);
bool cmp_write_double(struct cmp_ctx_s *ctx, double d);

bool cmp_write_nil(struct cmp_ctx_s *ctx);
bool cmp_write_true(struct cmp_ctx_s *ctx);
bool cmp_write_false(struct cmp_ctx_s *ctx);

bool cmp_write_fixstr_marker(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_fixstr(struct cmp_ctx_s *ctx, const void *data, size_t size);
bool cmp_write_str16_marker(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_str16(struct cmp_ctx_s *ctx, const void *data, size_t size);
bool cmp_write_str32_marker(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_str32(struct cmp_ctx_s *ctx, const void *data, size_t size);
bool cmp_write_str(struct cmp_ctx_s *ctx, const void *data, size_t size);

bool cmp_write_fixarray(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_array16(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_array32(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_array(struct cmp_ctx_s *ctx, size_t size);

bool cmp_write_fixmap(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_map16(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_map32(struct cmp_ctx_s *ctx, size_t size);
bool cmp_write_map(struct cmp_ctx_s *ctx, size_t size);

bool cmp_write_object(struct cmp_ctx_s *ctx, struct cmp_object_s *obj);

bool cmp_read_pfix(struct cmp_ctx_s *ctx, uint8_t *c);
bool cmp_read_nfix(struct cmp_ctx_s *ctx, int8_t *c);

bool cmp_read_sfix(struct cmp_ctx_s *ctx, int8_t *c);
bool cmp_read_s8(struct cmp_ctx_s *ctx, int8_t *c);
bool cmp_read_s16(struct cmp_ctx_s *ctx, int16_t *s);
bool cmp_read_s32(struct cmp_ctx_s *ctx, int32_t *i);
bool cmp_read_s64(struct cmp_ctx_s *ctx, int64_t *l);
bool cmp_read_sint(struct cmp_ctx_s *ctx, int64_t *l);

bool cmp_read_ufix(struct cmp_ctx_s *ctx, uint8_t *c);
bool cmp_read_u8(struct cmp_ctx_s *ctx, uint8_t *c);
bool cmp_read_u16(struct cmp_ctx_s *ctx, uint16_t *s);
bool cmp_read_u32(struct cmp_ctx_s *ctx, uint32_t *i);
bool cmp_read_u64(struct cmp_ctx_s *ctx, uint64_t *l);

bool cmp_read_float(struct cmp_ctx_s *ctx, float *f);
bool cmp_read_double(struct cmp_ctx_s *ctx, double *d);

bool cmp_read_nil(struct cmp_ctx_s *ctx);
bool cmp_read_bool(struct cmp_ctx_s *ctx, bool *b);
bool cmp_read_bool_as_u8(struct cmp_ctx_s *ctx, uint8_t *b);

bool cmp_read_str_size(struct cmp_ctx_s *ctx, size_t *size);
bool cmp_read_str(struct cmp_ctx_s *ctx, void *data, size_t *size);

bool cmp_read_array(struct cmp_ctx_s *ctx, size_t *size);

bool cmp_read_map(struct cmp_ctx_s *ctx, size_t *size);

bool cmp_read_object(struct cmp_ctx_s *ctx, struct cmp_object_s *obj);

/* vi: set et ts=2 sw=2: */

