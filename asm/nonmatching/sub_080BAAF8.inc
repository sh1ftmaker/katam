	.syntax unified
	.text

	push {r4, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BAB0C
	cmp r1, #0xc0
	bne _080BAB44
_080BAB0C:
	mov r0, ip
	adds r0, #0x3c
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x40]
	adds r4, r0, r2
	ldr r3, [r1, #0x44]
	ldr r0, _080BAB38 @ =0xFFFFF000
	ands r4, r0
	ldr r0, _080BAB3C @ =0x00000FFF
	adds r1, r4, r0
	ands r3, r0
	ldr r4, _080BAB40 @ =0xFFFFF800
	adds r0, r3, r4
	lsls r0, r0, #1
	subs r1, r1, r0
	subs r1, r1, r2
	mov r0, ip
	str r1, [r0, #0x40]
	b _080BAB6E
	.align 2, 0
_080BAB38: .4byte 0xFFFFF000
_080BAB3C: .4byte 0x00000FFF
_080BAB40: .4byte 0xFFFFF800
_080BAB44:
	mov r1, ip
	ldr r4, [r1, #0x40]
	mov r0, ip
	adds r0, #0x3d
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	ldr r0, [r1, #0x44]
	adds r3, r0, r2
	ldr r0, _080BAB74 @ =0xFFFFF0FF
	ands r3, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r4, r1
	asrs r0, r4, #1
	subs r0, r1, r0
	ands r0, r1
	adds r0, r3, r0
	subs r0, r0, r2
	mov r4, ip
	str r0, [r4, #0x44]
_080BAB6E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAB74: .4byte 0xFFFFF0FF

	.syntax divided
