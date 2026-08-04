	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r3, sp
	ldr r0, [r4, #0x40]
	adds r1, r4, #0
	adds r1, #0xb0
	ldr r2, [r1]
	asrs r0, r0, #8
	ldrh r1, [r2, #0x1a]
	adds r0, r0, r1
	strh r0, [r3]
	mov r1, sp
	ldr r0, [r4, #0x44]
	asrs r0, r0, #8
	ldrh r3, [r2, #0x1c]
	adds r0, r0, r3
	strh r0, [r1, #2]
	mov r3, sp
	ldrh r0, [r2, #0x1e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0, #2]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #6]
	ldr r2, _081208E0 @ =gCurLevelInfo
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r0, [r0]
	movs r1, #0xcd
	lsls r1, r1, #3
	muls r0, r1, r0
	adds r0, r0, r2
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	str r0, [sp, #8]
	movs r5, #0
	ldr r0, _081208E4 @ =gUnk_0203AD44
	mov sl, r0
	ldrb r0, [r0]
	cmp r5, r0
	bhs _081208C8
	mov sb, r2
	mov r8, r1
	mov r6, sp
_081207F4:
	mov r0, r8
	muls r0, r5, r0
	add r0, sb
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	bne _081208BA
	adds r7, r4, #0
	adds r7, #0xb0
	ldr r0, [r7]
	ldrh r1, [r0, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08120820
	ldr r0, _081208E8 @ =gUnk_0203AD30
	ldrb r0, [r0]
	cmp r5, r0
	blo _081208BA
_08120820:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08120830
	ldr r0, _081208E8 @ =gUnk_0203AD30
	ldrb r0, [r0]
	cmp r5, r0
	bhs _081208BA
_08120830:
	movs r3, #0
	ldrsh r2, [r6, r3]
	ldr r0, _081208EC @ =gKirbys
	mov ip, r0
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r3, r5, #0
	muls r3, r0, r3
	mov r0, ip
	adds r0, #0x40
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r1, r0, #8
	cmp r2, r1
	bgt _081208BA
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _081208BA
	movs r0, #2
	ldrsh r2, [r6, r0]
	mov r0, ip
	adds r0, #0x44
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r1, r0, #8
	cmp r2, r1
	bgt _081208BA
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _081208BA
	mov r0, ip
	adds r0, #0xc
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _081208BA
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r0, [r0]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	add r0, sb
	ldr r1, _081208F0 @ =0x0000065E
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0
	movs r1, #0xf
	bl sub_08002888
	adds r2, r0, #0
	ldr r0, [r7]
	ldrb r1, [r0, #0x11]
	ldr r0, [r2]
	cmp r0, r1
	bhs _081208AC
	str r1, [r2]
_081208AC:
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r4, #8]
	ldr r2, _081208E4 @ =gUnk_0203AD44
	mov sl, r2
_081208BA:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r3, sl
	ldrb r3, [r3]
	cmp r5, r3
	blo _081207F4
_081208C8:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081208E0: .4byte gCurLevelInfo
_081208E4: .4byte gUnk_0203AD44
_081208E8: .4byte gUnk_0203AD30
_081208EC: .4byte gKirbys
_081208F0: .4byte 0x0000065E

	.syntax divided
