//�x���z����Œ�K�v�ȍd�݂̖������v�Z����v���O����
#include <stdio.h>
#define ACCOUNTING_MAX 1000
const unsigned int units[] ={500, 100, 50, 10, 5, 1};
#define unit_count (sizeof(units)/sizeof(units[0]))
#define Unit_Count_MAX 10
//�󋵂ɉ����ĕω�������萔�͂Ȃ�ׂ���Ɏ����Ă���
//define��p���邱�ƂŃ}�W�b�N�i���o�[(�l�̈Ӗ����s���ĂȐ��l)���Ȃ���
int main(void)
{	//�C���f���e�[�V�������s�����ƂŎ��F�����i�i�Ɍ��シ��
	unsigned int i, accounting, buffer;
		//�ϐ����͈Ӗ��������̂ɂ���Ɨǂ�
		//�܂��{���v���O�������ňӖ��̕ς��ϐ��͐錾���Ȃ��ق����ǂ�
		//C�ɂ����ĕϐ��錾�͈�ԍŏ��ł����ł��Ȃ�
	unsigned int count[Unit_Count_MAX];
		//C�ł͐錾����z��̑傫���̓R���p�C�����Ɍ��肳��Ă���K�v������
		//(���I�ɕω���������@�����邪�A�|�C���^�̊T�O��p���邤����~~�ʓ|~~���G�Ȃ��ߍ���͎g�p���Ȃ�)
	puts("�x���z����Œ�K�v�ȍd�݂̖������v�Z���܂�");
	printf("�x���z����͂��Ă�������(1 ... %d)\n", ACCOUNTING_MAX-1);
	do	//goto��do-while�ő�p�ł���
	{
		printf("> ");
		scanf("%u", &accounting);
		if(accounting<=0 || accounting>=ACCOUNTING_MAX)
			printf("%u�͖����Ȓl�ł��B1 ... %d�͈͓̔��œ��͂��Ă�������\n", accounting, ACCOUNTING_MAX-1);
	} while(accounting<=0 || accounting>=ACCOUNTING_MAX);

	printf("�x�����z: %u", accounting);

	for (i= 0; i<unit_count; ++i)
	{
		if(units[i]==0)
		{
			//���X�ɗ�O�����������Ă����_�ɂ��Ắ�
			printf("�g�p����d�݂ɖ�肪������܂����B\n�g�p����d�݂̍Ċm�F���s���Ă��������B");
			return -1;
		}
		else
		{
			buffer= accounting % units[i];
			count[i]= (accounting - buffer) / units[i];
			accounting= buffer;
		}
		if(accounting==0)
			break;
		//����؂ꂽ�i�K�ŏ�����؂�グ��
	}
	if(accounting==0)
		//����؂ꂽ���ǂ����̔���(����؂ꂽ�ꍇ��0�ɂȂ�)
	{
		puts("�x�����ɕK�v�ȍd�݂̖���");
		buffer= 0;
		for(i=0; i<unit_count; i++)
		{
			printf("%u�~��: %u��\n", units[i], count[i]);
			buffer+= count[i];
		}
		printf("���v: %u��", buffer);
		return 0;
	}
	else
	{
		puts("�x�����z�ɑ΂��A�w�肳�ꂽ���ʂ̎�ނł͊���؂�܂���ł����B\n�g�p����d�݂̍Ċm�F���s���Ă��������B");
		return -1;
	}
}