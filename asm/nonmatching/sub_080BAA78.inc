	.syntax unified
	.text

	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BAA8C
	cmp r1, #0xc0
	bne _080BAABC
_080BAA8C:
	mov r0, ip
	adds r0, #0x3c
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x40]
	adds r4, r0, r2
	ldr r5, [r1, #0x44]
	ldr r0, _080BAAB4 @ =0xFFFFF000
	ands r4, r0
	ldr r1, _080BAAB8 @ =0x00000FFF
	adds r0, r4, r1
	ands r5, r1
	lsls r1, r5, #1
	subs r0, r0, r1
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BAAE8
	.align 2, 0
_080BAAB4: .4byte 0xFFFFF000
_080BAAB8: .4byte 0x00000FFF
_080BAABC:
	mov r0, ip
	ldr r4, [r0, #0x40]
	adds r0, #0x3d
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r5, r0, r2
	ldr r0, _080BAAF0 @ =0xFFFFF0FF
	ands r5, r0
	movs r3, #0xf0
	lsls r3, r3, #4
	ands r4, r3
	asrs r1, r4, #1
	ldr r0, _080BAAF4 @ =0x000007FF
	subs r0, r0, r1
	ands r0, r3
	adds r0, r5, r0
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x44]
_080BAAE8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BAAF0: .4byte 0xFFFFF0FF
_080BAAF4: .4byte 0x000007FF

	.syntax divided
