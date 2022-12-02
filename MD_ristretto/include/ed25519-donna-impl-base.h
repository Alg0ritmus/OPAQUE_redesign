/*
	conversions
*/

DONNA_INLINE static void
ge25519_p1p1_to_full(ge25519 *r, const ge25519_p1p1 *p) {
	curve25519_mul(r->x, p->x, p->t);
	curve25519_mul(r->y, p->y, p->z);
	curve25519_mul(r->z, p->z, p->t); 
	curve25519_mul(r->t, p->x, p->y); 
}

/*
	adding & doubling
*/

static void
ge25519_add_p1p1(ge25519_p1p1 *r, const ge25519 *p, const ge25519 *q) {
	bignum25519 a,b,c,d,t,u;

	curve25519_sub(a, p->y, p->x);
	curve25519_add(b, p->y, p->x);
	curve25519_sub(t, q->y, q->x);
	curve25519_add(u, q->y, q->x);
	curve25519_mul(a, a, t);
	curve25519_mul(b, b, u);
	curve25519_mul(c, p->t, q->t);
	curve25519_mul(c, c, ge25519_ec2d);
	curve25519_mul(d, p->z, q->z);
	curve25519_add(d, d, d);
	curve25519_sub(r->x, b, a);
	curve25519_add(r->y, b, a);
	curve25519_add_after_basic(r->z, d, c);
	curve25519_sub_after_basic(r->t, d, c);
}

static void
ge25519_add(ge25519 *r, const ge25519 *p,  const ge25519 *q) {
	ge25519_p1p1 t;
	ge25519_add_p1p1(&t, p, q);
	ge25519_p1p1_to_full(r, &t);
}


