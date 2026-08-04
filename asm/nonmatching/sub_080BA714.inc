	.syntax unified
	.text

	push {lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BA728
	cmp r1, #0xc0
	bne _080BA754
_080BA728:
	mov r0, ip
	adds r0, #0x3e
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	mov r2, ip
	ldr r0, [r2, #0x40]
	adds r3, r0, r1
	ldr r2, [r2, #0x44]
	ldr r0, _080BA750 @ =0xFFFFF0FF
	ands r3, r0
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r2, r0
	adds r0, r3, r2
	subs r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BA778
	.align 2, 0
_080BA750: .4byte 0xFFFFF0FF
_080BA754:
	mov r2, ip
	ldr r3, [r2, #0x40]
	mov r0, ip
	adds r0, #0x3d
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r2, #0x44]
	adds r2, r0, r1
	ldr r0, _080BA77C @ =0xFFFFF0FF
	ands r2, r0
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r3, r0
	adds r0, r2, r3
	subs r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x44]
_080BA778:
	pop {r0}
	bx r0
	.align 2, 0
_080BA77C: .4byte 0xFFFFF0FF

	.syntax divided
