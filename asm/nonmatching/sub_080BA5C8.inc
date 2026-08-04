	.syntax unified
	.text

	push {r4, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BA5DC
	cmp r1, #0xc0
	bne _080BA608
_080BA5DC:
	mov r0, ip
	adds r0, #0x3e
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x40]
	adds r4, r0, r2
	ldr r3, [r1, #0x44]
	ldr r0, _080BA604 @ =0xFFFFF0FF
	ands r4, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r4, r1
	ands r3, r1
	subs r0, r0, r3
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BA62E
	.align 2, 0
_080BA604: .4byte 0xFFFFF0FF
_080BA608:
	mov r0, ip
	ldr r4, [r0, #0x40]
	adds r0, #0x3f
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r3, r0, r2
	ldr r0, _080BA634 @ =0xFFFFF0FF
	ands r3, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r3, r1
	ands r4, r1
	subs r0, r0, r4
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x44]
_080BA62E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA634: .4byte 0xFFFFF0FF

	.syntax divided
