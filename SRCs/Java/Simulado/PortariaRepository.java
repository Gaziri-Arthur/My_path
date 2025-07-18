package Simulado;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

//import br.edu.ifpr.list004.model.Portaria;

public enum PortariaRepository {
   INSTANCE; // Única instância do singleton

   private final List<Portaria> portarias = new ArrayList<>();

   PortariaRepository() {
      // incluir vários objetos Portaria no "banco de dados"
       portarias.add(new Portaria());
   }

   public synchronized boolean inserir(Portaria portaria) {
      return false;
   }

   public synchronized boolean alterar(Portaria portaria) {
      return false;
   }

   public synchronized boolean excluir(String emissor) {
      return false;
   }

   public Optional<Portaria> buscarPorEmissor(String emissor) {
      return Optional.empty();
   }

   public Optional<Portaria> buscarPorNumero(Integer number) {
      return Optional.empty();
   }

   public List<Portaria> buscarPorPeríodo(LocalDate start, LocalDate end) {
      return Collections.emptyList();
   }

   public List<Portaria> buscarPorPublicação(LocalDate start) {
      return Collections.emptyList();
   }

   public List<Portaria> buscarPorNome(String nome) {
      return Collections.emptyList();
   }

   public List<Portaria> listarTodas() {
      return Collections.emptyList();
   }
}
