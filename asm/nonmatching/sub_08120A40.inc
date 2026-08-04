	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r1, sb
	adds r0, r1, #0
	str r0, [sp]
	movs r2, #0
	strh r2, [r1, #4]
	ldr r1, _08120B84 @ =gUnk_08357D20
	mov r3, sb
	adds r3, #0xb0
	ldr r0, [r3]
	ldrh r0, [r0, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sb
	adds r4, #0xb4
	strh r0, [r4]
	ldr r0, [r3]
	ldrh r0, [r0, #0x14]
	mov r1, sb
	adds r1, #0xb6
	strh r0, [r1]
	mov r0, sb
	adds r0, #0xb8
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	bl EwramMalloc
	adds r1, r0, #0
	mov r0, sb
	adds r0, #0x8c
	str r1, [r0]
	subs r0, #0x36
	ldrb r0, [r0]
	str r0, [sp, #4]
	mov r2, sb
	ldr r0, [r2, #0x40]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, [r2, #0x44]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	mov sl, r0
	ldrh r4, [r4]
	cmp r0, r4
	bhs _08120B6E
	ldr r2, [sp, #8]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x14]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #8
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x18]
_08120AD0:
	ldr r0, [sp]
	adds r0, #0xb6
	ldrh r0, [r0]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	adds r0, r2, r1
	ldr r2, _08120B88 @ =gUnk_08357D30
	adds r0, r0, r2
	movs r5, #0
	ldrsb r5, [r0, r5]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #1
	add sl, r0
	add r1, sl
	adds r1, r1, r2
	movs r4, #0
	ldrsb r4, [r1, r4]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	add sl, r0
	ldr r1, [sp, #8]
	adds r1, r1, r5
	mov r8, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [sp, #0xc]
	adds r6, r2, r4
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	ldr r0, [sp, #4]
	bl sub_080025AC
	str r0, [r7, #0x14]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r0, [sp, #0x14]
	adds r5, r0, r5
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [sp, #0x18]
	adds r4, r1, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [sp, #4]
	adds r1, r5, #0
	adds r2, r4, #0
	ldr r3, [sp, #0x1c]
	bl sub_080015A8
	ldr r0, [sp, #4]
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_080023E4
	strb r0, [r7, #0x10]
	movs r0, #1
	strb r0, [r7]
	mov r2, r8
	strb r2, [r7, #2]
	strb r6, [r7, #3]
	movs r0, #0x14
	strh r0, [r7, #4]
	adds r7, #0x18
	ldr r0, [sp, #0x1c]
	adds r0, #0x18
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, [sp]
	adds r0, #0xb4
	ldrh r0, [r0]
	cmp r1, r0
	blo _08120AD0
_08120B6E:
	ldr r0, _08120B8C @ =sub_08120B90
	mov r2, sb
	str r0, [r2, #0x78]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08120B84: .4byte gUnk_08357D20
_08120B88: .4byte gUnk_08357D30
_08120B8C: .4byte sub_08120B90

	.syntax divided
