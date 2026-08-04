	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r7, _08120780 @ =gCurLevelInfo
	adds r0, #0x56
	ldrb r0, [r0]
	movs r5, #0xcd
	lsls r5, r5, #3
	muls r0, r5, r0
	adds r0, r0, r7
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	mov sb, r0
	adds r0, r4, #0
	bl sub_08039490
	adds r6, r0, #0
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
	ldr r0, [r6]
	cmp r0, #0
	beq _0812076C
	mov r8, r7
	adds r7, r5, #0
	mov r5, sp
_081206DA:
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0x56
	ldrb r0, [r0]
	muls r0, r7, r0
	add r0, r8
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp sb, r0
	bne _08120764
	adds r0, r1, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0x79
	beq _08120700
	cmp r0, #0x7d
	bne _08120764
_08120700:
	ldr r0, [r1, #0x40]
	lsls r0, r0, #8
	ldr r1, [r1, #0x44]
	lsls r1, r1, #8
	lsrs r3, r1, #0x10
	movs r2, #0
	ldrsh r1, [r5, r2]
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _08120764
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _08120764
	ldrh r0, [r5, #2]
	lsls r0, r0, #0x10
	lsls r1, r3, #0x10
	asrs r2, r1, #0x10
	cmp r0, r1
	bgt _08120764
	movs r3, #6
	ldrsh r0, [r5, r3]
	cmp r0, r2
	blt _08120764
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r0, [r0]
	muls r0, r7, r0
	add r0, r8
	ldr r1, _08120784 @ =0x0000065E
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0
	movs r1, #0xf
	bl sub_08002888
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrb r1, [r0, #0x11]
	ldr r0, [r2]
	cmp r0, r1
	bhs _0812075A
	str r1, [r2]
_0812075A:
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r4, #8]
_08120764:
	adds r6, #4
	ldr r0, [r6]
	cmp r0, #0
	bne _081206DA
_0812076C:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08120780: .4byte gCurLevelInfo
_08120784: .4byte 0x0000065E

	.syntax divided
