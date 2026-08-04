	.syntax unified
	.text

	push {r4, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BA6B8
	cmp r1, #0xc0
	bne _080BA6E4
_080BA6B8:
	mov r0, ip
	adds r0, #0x3c
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x40]
	adds r4, r0, r2
	ldr r3, [r1, #0x44]
	ldr r0, _080BA6E0 @ =0xFFFFF0FF
	ands r4, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r4, r1
	ands r3, r1
	subs r0, r0, r3
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BA70A
	.align 2, 0
_080BA6E0: .4byte 0xFFFFF0FF
_080BA6E4:
	mov r0, ip
	ldr r4, [r0, #0x40]
	adds r0, #0x3d
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r3, r0, r2
	ldr r0, _080BA710 @ =0xFFFFF0FF
	ands r3, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r3, r1
	ands r4, r1
	subs r0, r0, r4
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x44]
_080BA70A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA710: .4byte 0xFFFFF0FF

	.syntax divided
