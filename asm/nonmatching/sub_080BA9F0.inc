	.syntax unified
	.text

	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BAA04
	cmp r1, #0xc0
	bne _080BAA3C
_080BAA04:
	mov r0, ip
	adds r0, #0x3e
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	mov r2, ip
	ldr r0, [r2, #0x40]
	adds r5, r0, r1
	ldr r4, [r2, #0x44]
	ldr r0, _080BAA30 @ =0xFFFFF000
	ands r5, r0
	ldr r0, _080BAA34 @ =0x00000FFF
	ands r4, r0
	ldr r2, _080BAA38 @ =0xFFFFF800
	adds r0, r4, r2
	lsls r0, r0, #1
	adds r0, r5, r0
	subs r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BAA6C
	.align 2, 0
_080BAA30: .4byte 0xFFFFF000
_080BAA34: .4byte 0x00000FFF
_080BAA38: .4byte 0xFFFFF800
_080BAA3C:
	mov r2, ip
	ldr r5, [r2, #0x40]
	mov r0, ip
	adds r0, #0x3d
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r4, r0, r2
	ldr r0, _080BAA74 @ =0xFFFFF0FF
	ands r4, r0
	movs r3, #0xf0
	lsls r3, r3, #4
	ands r5, r3
	asrs r0, r5, #1
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	ands r0, r3
	adds r0, r4, r0
	subs r0, r0, r2
	mov r2, ip
	str r0, [r2, #0x44]
_080BAA6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BAA74: .4byte 0xFFFFF0FF

	.syntax divided
