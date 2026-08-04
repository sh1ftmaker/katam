	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	mov r1, ip
	adds r1, #0xb0
	ldr r0, [r1]
	ldrh r0, [r0, #6]
	mov r2, ip
	adds r2, #0xc0
	strh r0, [r2]
	ldr r0, [r1]
	ldrh r3, [r0, #8]
	mov r4, ip
	adds r4, #0xc2
	strh r3, [r4]
	mov r0, ip
	adds r0, #0xc4
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0811F4A0
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0811F478
	cmp r1, #1
	bgt _0811F45E
	cmp r1, #0
	beq _0811F468
	b _0811F4A0
_0811F45E:
	cmp r1, #2
	beq _0811F484
	cmp r1, #3
	beq _0811F494
	b _0811F4A0
_0811F468:
	mov r0, ip
	adds r0, #0xb6
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	b _0811F4A0
_0811F478:
	mov r0, ip
	adds r0, #0xb6
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, r3, r0
	b _0811F49E
_0811F484:
	mov r0, ip
	adds r0, #0xb6
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	b _0811F4A0
_0811F494:
	mov r0, ip
	adds r0, #0xb6
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r3, r0
_0811F49E:
	strh r0, [r4]
_0811F4A0:
	mov r2, ip
	adds r2, #0xc4
	ldrh r0, [r2]
	ldr r5, _0811F4D4 @ =0x0000FFE0
	ands r5, r0
	movs r7, #0
	strh r5, [r2]
	mov r0, ip
	adds r0, #0xc0
	ldr r4, [r0]
	mov r1, ip
	adds r1, #0xb8
	ldr r3, [r1]
	mov sl, r0
	adds r6, r2, #0
	mov sb, r1
	cmp r4, r3
	bne _0811F4D8
	movs r1, #0x10
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0xba
	add r2, ip
	mov r8, r2
	b _0811F538
	.align 2, 0
_0811F4D4: .4byte 0x0000FFE0
_0811F4D8:
	mov r3, sl
	movs r0, #0
	ldrsh r4, [r3, r0]
	mov r1, sb
	movs r2, #0
	ldrsh r3, [r1, r2]
	cmp r4, r3
	beq _0811F512
	movs r0, #0xc2
	add r0, ip
	mov r8, r0
	mov r0, ip
	adds r0, #0xba
	mov r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	str r1, [sp]
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r8, r0
	ldr r0, [sp]
	cmp r0, r1
	bne _0811F538
	cmp r3, r4
	bge _0811F50E
	movs r1, #4
	b _0811F532
_0811F50E:
	movs r1, #1
	b _0811F532
_0811F512:
	mov r1, ip
	adds r1, #0xc2
	mov r0, ip
	adds r0, #0xba
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r8, r0
	cmp r2, r1
	beq _0811F538
	cmp r1, r2
	bge _0811F530
	movs r1, #8
	b _0811F532
_0811F530:
	movs r1, #2
_0811F532:
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r6]
_0811F538:
	ldrh r1, [r6]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	cmp r1, #2
	beq _0811F5BE
	cmp r1, #2
	bgt _0811F556
	cmp r1, #1
	beq _0811F560
	b _0811F674
_0811F556:
	cmp r1, #4
	beq _0811F5EE
	cmp r1, #8
	beq _0811F64C
	b _0811F674
_0811F560:
	mov r2, ip
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	beq _0811F590
	mov r1, ip
	adds r1, #0x50
	adds r2, #0xb5
	ldrh r0, [r1]
	ldrb r3, [r2]
	adds r0, r0, r3
	strh r0, [r1]
	movs r4, #0
	ldrsh r3, [r1, r4]
	ldrb r0, [r2]
	rsbs r2, r0, #0
	cmp r3, r2
	bge _0811F588
	strh r2, [r1]
	b _0811F5B2
_0811F588:
	cmp r3, r0
	ble _0811F5B2
	strh r0, [r1]
	b _0811F5B2
_0811F590:
	mov r2, ip
	adds r2, #0x50
	mov r3, ip
	adds r3, #0xb5
	ldrb r1, [r3]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	movs r7, #0
	ldrsh r1, [r2, r7]
	ldrb r0, [r3]
	cmp r1, r0
	bgt _0811F5B0
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811F5B2
_0811F5B0:
	strh r0, [r2]
_0811F5B2:
	mov r1, ip
	ldr r0, [r1, #0x40]
	asrs r0, r0, #8
	mov r2, sb
	strh r0, [r2]
	b _0811F674
_0811F5BE:
	mov r3, ip
	adds r3, #0xb5
	ldrb r0, [r3]
	cmp r0, #0
	beq _0811F5E2
	mov r1, ip
	adds r1, #0x52
	ldrh r0, [r1]
	ldrb r4, [r3]
	adds r0, r0, r4
	strh r0, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	ldrb r2, [r3]
	cmp r0, r2
	ble _0811F66A
	strh r2, [r1]
	b _0811F66A
_0811F5E2:
	mov r2, ip
	adds r2, #0x52
	ldrh r0, [r2]
	ldrb r1, [r3]
	adds r0, r0, r1
	b _0811F65A
_0811F5EE:
	mov r2, ip
	ldr r0, [r2, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811F620
	adds r2, #0x50
	mov r4, ip
	adds r4, #0xb5
	ldrb r1, [r4]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	movs r7, #0
	ldrsh r3, [r2, r7]
	ldrb r0, [r4]
	rsbs r1, r0, #0
	cmp r3, r1
	bge _0811F618
	strh r1, [r2]
	b _0811F642
_0811F618:
	cmp r3, r0
	ble _0811F642
	strh r0, [r2]
	b _0811F642
_0811F620:
	mov r1, ip
	adds r1, #0x50
	mov r3, ip
	adds r3, #0xb5
	ldrh r0, [r1]
	ldrb r2, [r3]
	adds r0, r0, r2
	strh r0, [r1]
	movs r4, #0
	ldrsh r2, [r1, r4]
	ldrb r0, [r3]
	cmp r2, r0
	bgt _0811F640
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0811F642
_0811F640:
	strh r0, [r1]
_0811F642:
	mov r7, ip
	ldr r0, [r7, #0x40]
	asrs r0, r0, #8
	mov r1, sb
	b _0811F672
_0811F64C:
	mov r3, ip
	adds r3, #0xb5
	ldrb r4, [r3]
	mov r2, ip
	adds r2, #0x52
	ldrh r0, [r2]
	subs r0, r0, r4
_0811F65A:
	strh r0, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldrb r0, [r3]
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811F66A
	strh r0, [r2]
_0811F66A:
	mov r7, ip
	ldr r0, [r7, #0x44]
	asrs r0, r0, #8
	mov r1, r8
_0811F672:
	strh r0, [r1]
_0811F674:
	ldrh r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	cmp r1, #2
	beq _0811F6E4
	cmp r1, #2
	bgt _0811F688
	cmp r1, #1
	beq _0811F692
	b _0811F7B2
_0811F688:
	cmp r1, #4
	beq _0811F718
	cmp r1, #8
	beq _0811F768
	b _0811F7B2
_0811F692:
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	mov r4, sb
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _0811F6A4
	b _0811F7BA
_0811F6A4:
	mov r1, ip
	adds r1, #0x50
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _0811F6C4
	ldr r4, _0811F6C0 @ =0x00007FFF
	adds r0, r2, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811F6D4
	b _0811F6D0
	.align 2, 0
_0811F6C0: .4byte 0x00007FFF
_0811F6C4:
	ldr r7, _0811F6E0 @ =0xFFFF8001
	adds r0, r2, r7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0811F6D4
_0811F6D0:
	movs r0, #0
	strh r0, [r1]
_0811F6D4:
	mov r1, sl
	ldrh r0, [r1]
	mov r2, sb
	strh r0, [r2]
	b _0811F7B2
	.align 2, 0
_0811F6E0: .4byte 0xFFFF8001
_0811F6E4:
	mov r0, ip
	adds r0, #0xc2
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r4, r8
	movs r7, #0
	ldrsh r1, [r4, r7]
	adds r3, r0, #0
	cmp r2, r1
	blt _0811F7BA
	mov r1, ip
	adds r1, #0x52
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _0811F79C
	ldr r7, _0811F714 @ =0x00007FFF
	adds r0, r2, r7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811F7AC
	b _0811F7A8
	.align 2, 0
_0811F714: .4byte 0x00007FFF
_0811F718:
	mov r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bgt _0811F7BA
	mov r1, ip
	adds r1, #0x50
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0
	bge _0811F748
	ldr r3, _0811F744 @ =0x00007FFF
	adds r0, r2, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811F758
	b _0811F754
	.align 2, 0
_0811F744: .4byte 0x00007FFF
_0811F748:
	ldr r4, _0811F764 @ =0xFFFF8001
	adds r0, r2, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0811F758
_0811F754:
	movs r0, #0
	strh r0, [r1]
_0811F758:
	mov r7, sl
	ldrh r0, [r7]
	mov r1, sb
	strh r0, [r1]
	b _0811F7B2
	.align 2, 0
_0811F764: .4byte 0xFFFF8001
_0811F768:
	mov r0, ip
	adds r0, #0xc2
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r4, r8
	movs r7, #0
	ldrsh r1, [r4, r7]
	adds r3, r0, #0
	cmp r2, r1
	bgt _0811F7BA
	mov r1, ip
	adds r1, #0x52
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _0811F79C
	ldr r7, _0811F798 @ =0x00007FFF
	adds r0, r2, r7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811F7AC
	b _0811F7A8
	.align 2, 0
_0811F798: .4byte 0x00007FFF
_0811F79C:
	ldr r4, _0811F818 @ =0xFFFF8001
	adds r0, r2, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0811F7AC
_0811F7A8:
	movs r0, #0
	strh r0, [r1]
_0811F7AC:
	ldrh r0, [r3]
	mov r7, r8
	strh r0, [r7]
_0811F7B2:
	ldrh r1, [r6]
	ldr r0, _0811F81C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r6]
_0811F7BA:
	ldr r3, _0811F820 @ =gCurLevelInfo
	movs r0, #0x56
	add r0, ip
	mov sl, r0
	ldrb r0, [r0]
	movs r5, #0xcd
	lsls r5, r5, #3
	adds r2, r0, #0
	muls r2, r5, r2
	adds r0, r3, #0
	adds r0, #0x2c
	adds r2, r2, r0
	mov r4, ip
	adds r4, #0xb0
	ldr r0, [r4]
	movs r1, #6
	ldrsh r0, [r0, r1]
	mov r6, sb
	movs r7, #0
	ldrsh r1, [r6, r7]
	subs r0, r0, r1
	lsls r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r2]
	mov r1, sl
	ldrb r0, [r1]
	adds r2, r0, #0
	muls r2, r5, r2
	adds r3, #0x30
	adds r2, r2, r3
	ldr r0, [r4]
	movs r3, #8
	ldrsh r0, [r0, r3]
	mov r4, r8
	movs r6, #0
	ldrsh r1, [r4, r6]
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F818: .4byte 0xFFFF8001
_0811F81C: .4byte 0x0000FEFF
_0811F820: .4byte gCurLevelInfo

	.syntax divided
