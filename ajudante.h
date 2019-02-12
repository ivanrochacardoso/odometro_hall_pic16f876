
/*
BIBLIOTECA AD E EEPROM PARA HODÔMETRO

*/


long AD(int channel)
  {
  long aux;
  switch(channel)
    {
    case 0 : input(PIN_A0); break;
    case 1 : input(PIN_A1); break;
    case 2 : input(PIN_A2); break;
    case 3 : input(PIN_A3); break;
    case 4 : input(PIN_A5); break;
    default: return(0);
    }

	
  set_adc_channel(channel);
  delay_us(100);
  aux = read_adc();

  return(aux);
  }



//================================================================

long long_read_eeprom(int pos)   // lê da posição pos e pos+1 da eeprom (16 bits)
  {                              // devolvendo um long
  long aux;
  aux = read_eeprom(pos+1);
  aux = (aux << 8) + read_eeprom(pos);
  return(aux);
  }

int32 int32_read_eeprom(int pos)   // lê da posição pos,pos+1,pos+2,pos+3 da eeprom (32 bits)
  {                               // devolvendo um int32
  int32 aux;
  aux = read_eeprom(pos+3);
  aux = (aux << 8) + read_eeprom(pos+2);
  aux = (aux << 8) + read_eeprom(pos+1);
  aux = (aux << 8) + read_eeprom(pos);
  return(aux);
  }


//corrigido abaixo por ivan em 31/março 2014 -  de 32 bits - alterado
void long_write_eeprom(int ender, long vlr)// escreve na posição ender  e ender+1 da eeprom (16 bits)
  {
 int aux, i;
  for(i=0; i<2; i ++)
    {
    aux=vlr%256;
    vlr = vlr >> 8;
    write_eeprom(ender+i, aux);
    }
  }

void int32_write_eeprom(int ender, int32 vlr)
  {
  int aux, i;
  for(i=0; i<4; i ++)
    {
    aux=vlr%256;
    vlr = vlr >> 8;
    write_eeprom(ender+i, aux);
    }
  }

