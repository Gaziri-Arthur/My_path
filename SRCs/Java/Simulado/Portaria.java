package Simulado;

import java.time.LocalDate;

public class Portaria {

    private Integer numero;
    private String emissor;
    private LocalDate publicacao;
    private String membro;

    public Portaria() {
    }

    public Portaria(int numero, String emissor, LocalDate publicacao, String membro) {
        this.numero = numero;
        this.emissor = emissor;
        this.publicacao = publicacao;
        this.membro = membro;
    }

    public Integer getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getEmissor() {
        return emissor;
    }

    public void setEmissor(String emissor) {
        this.emissor = emissor;
    }

    public LocalDate getPublicacao() {
        return publicacao;
    }

    public void setPublicacao(LocalDate publicacao) {
        this.publicacao = publicacao;
    }

    public String getMembro() {
        return membro;
    }

    public void setMembro(String membro) {
        this.membro = membro;
    }

    @Override
    public boolean equals(Object obj)
    {
        if(obj == null) return false;
        if(this.getClass() != obj.getClass()) return false;
        if(this == obj) return true;
 
        Portaria p = (Portaria) obj;
        if(!this.emissor.equals(p.emissor)) return false;
        if(!this.numero.equals(p.numero)) return false;
        if(!this.membro.equals(p.membro)) return false;
        if(!this.publicacao.equals(p.publicacao)) return false;

        return true;
    }

    @Override
    public String toString()
    {
        return "Portaria[emissor=" + emissor + "numero=" + 
        numero + " publicacao=" + publicacao + " membro=" + membro + "]";
    }

}
